#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y) : m_Model(model)
{
    //Convert inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

    start_node = &m_Model.FindClosestNode(start_x, start_y);
    end_node = &m_Model.FindClosestNode(end_x, end_y);
}

float RoutePlanner::CalculateHValue(RouteModel::Node const *node)
{
    float dist = node->distance(*end_node);
    return dist;
}

void RoutePlanner::AddNeighbors(RouteModel::Node *current_node)
{

    current_node->FindNeighbors();
    for (auto current : current_node->neighbors)
    {
        current->parent = current_node;
        current->g_value = current_node->g_value + current_node->distance(*current);
        current->h_value = RoutePlanner::CalculateHValue(current);
        open_list.emplace_back(current);
        current->visited = true;
    }
}

bool RoutePlanner::Compare(const RouteModel::Node *node_1, const RouteModel::Node *node_2)
{
    float first = node_1->h_value + node_1->g_value;
    float second = node_2->h_value + node_2->g_value;
    return first > second;
}

RouteModel::Node *RoutePlanner::NextNode()
{
    std::sort(open_list.begin(), open_list.end(), RoutePlanner::Compare);

    RouteModel::Node *lowest_sum = open_list.back();
    open_list.pop_back();
    return lowest_sum;
}

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node)
{
    // Create path_found vector
    distance = 0.0f;
    std::vector<RouteModel::Node> path_found;
    RouteModel::Node *cur_node = current_node;

    while (cur_node)
    {
        path_found.push_back(*cur_node);
        if (cur_node->parent)
        {
            distance += cur_node->distance(*cur_node->parent);
            cur_node = cur_node->parent;
        }
        else
        {
            break;
        }
    }

    std::reverse(path_found.begin(), path_found.end());
    distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
    return path_found;
}

void RoutePlanner::AStarSearch()
{

    start_node->visited = true;
    open_list.push_back(start_node);
    RouteModel::Node *current_node = nullptr;

    while (!open_list.empty())
    {

        current_node = NextNode();
        if (current_node->distance(*end_node) == 0)
        {
            m_Model.path = ConstructFinalPath(current_node);
            return;
        }
        else
        {
            AddNeighbors(current_node);
        }
    }
}