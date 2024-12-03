# Linux System Monitor using C++


The System Monitor is a C++ application designed to provide real-time information about system resources and processes. Inspired by the Task Manager in Windows, this tool offers insights into CPU usage, RAM utilization, and currently running processes.

The application leverages the [ncurses](https://www.gnu.org/software/ncurses/) library to create an interactive terminal-based user interface, ensuring efficient and clear visualization of system metrics.

## Features

- **CPU Monitoring:** Displays real-time CPU utilization.
- **Memory Usage:** Tracks and reports RAM consumption.
- **Process Management:** Lists running processes along with key details.

## Requirements

- **C++ Compiler:** Compatible with modern C++ standards (C++17 or higher since using std::filesystem).
- **Ncurses Library:** Required for the terminal-based interface. Install via your system’s package manager



This project was developed as part of the Udacity C++ Nanodegree program. It incorporates advanced C++ concepts, including object-oriented programming, and utilizes **Make** for building the system. Designed for Linux environments, this tool provides an efficient way to retrieve detailed information about underlying processes.

## ncurses
[ncurses](https://www.gnu.org/software/ncurses/) is a library that facilitates text-based graphical output in the terminal. This project relies on ncurses for display output.


To install ncurses within your own Linux environment: 

`sudo apt install libncurses5-dev libncursesw5-dev`

## Make
This project uses [Make](https://www.gnu.org/software/make/). The Makefile has four targets:
* `build` compiles the source code and generates an executable
* `format` applies [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) to style the source code
* `debug` compiles the source code and generates an executable, including debugging symbols
* `clean` deletes the `build/` directory, including all of the build artifacts

## Instructions

1. Clone the project repository: 

    `git clone https://github.com/ronyshaji/Udacity_CPP.git`

2. Build the project: 

    `make build`

3. Run the resulting executable: 

    `./build/monitor` and the terminal opens.


![System Monitor](images/monitor.png)


## Contributing

Contributions are welcome! Feel free to submit issues or pull requests to improve the tool further.