# Udacity C++ Nanodegree Projects and Notes

This repository contains projects and notes completed as part of the Udacity C++ Nanodegree program. The projects demonstrate advanced C++ programming concepts, including object-oriented programming, data structures, algorithms, and system programming. The repository also includes comprehensive notes for reference and learning.

## Contents

- **Notes**

    Detailed notes summarizing key concepts from the Udacity C++ Nanodegree tutorials.
	-	Format: PDF
	-	Topics include: Advanced C++ concepts, object-oriented programming, memory management, and best practices.

- **Project 1:**  [OpenStreetMap Route Planning](https://github.com/ronyshaji/Udacity_CPP/tree/main/Build_OpenStreetMap_Route_Finder)

    Implementation of a route planning tool using the A* search algorithm to find the shortest path between two points on a map.

- **Project 2:** [Linux System Monitor](https://github.com/ronyshaji/Udacity_CPP/tree/main/Linux_System_Monitor)

    A terminal-based system monitor tool inspired by the Linux Task Manager, providing real-time insights into CPU, memory usage, and processes.

## Project 1: OpenStreetMap Route Planning Project

### Overview

This project demonstrates the use of the A* search algorithm to calculate the shortest route between two points on an OpenStreetMap.

**Key Features**

- Parses OpenStreetMap data using the IO2D library.
- Implements the A* algorithm for efficient route planning.
- Visualizes the calculated path on the map.

**Technologies Used**

- Programming Language: C++
- Libraries: IO2D, STL containers
- Algorithm: A* search

**Usage**

- Clone the repository and navigate to the project directory.
- Build the project using the provided Makefile or CMake configuration.
- Run the executable to load the map and select start and end points.

## Project 2: Linux System Monitor

### Overview

This terminal-based tool provides insights into the Linux system’s performance, including CPU and memory usage and details of running processes. It is inspired by the Windows Task Manager.

**Key Features**

- Displays real-time information about system resources.
- Lists running processes with detailed metrics.
- Interactive interface powered by the ncurses library.

**Technologies Used**

- Programming Language: C++
- Libraries: ncurses
- Build Tool: Make

**Usage**

- Clone the repository and navigate to the project directory.
- Build the project using the provided Makefile.
- Run the executable to monitor the system.

## Setup and Installation

- Clone the repository:

    `git clone https://github.com/ronyshaji/Udacity_CPP.git`

- Navigate to the project directory:

    `cd Udacity_CPP`

- Follow the specific instructions in each project directory to build and run the projects.