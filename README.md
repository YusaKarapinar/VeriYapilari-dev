
# VeriYapisi Project

## Overview
The **VeriYapisi** project is designed for working with genetic data structures such as DNA, genes, and chromosomes. It includes source code for managing these biological structures and simulates various data structure algorithms.

## Project Structure
```
VeriYapisi/
│── .vscode/            # VSCode configuration files
│── bin/                # Compiled binaries
│── doc/                # Project documentation
│── include/            # Header files
│── lib/                # Library files
│── src/                # Source code files
│   │── DNA.cpp
│   │── Gen.cpp
│   │── Kromozom.cpp
│   │── main.cpp
│── dna.txt             # Sample DNA data
│── makefile            # Makefile for project compilation
```

## Requirements
- **Compiler:** A C++ compiler such as `g++`.
- **Build Tools:** `make` utility (for Linux/Mac).
- **IDE (Optional):** Visual Studio Code or another C++ IDE.

## How to Build and Run
1. **Clone the Repository:**
   ```
   git clone <repository-url>
   cd VeriYapisi
   ```

2. **Build the Project:**
   ```
   make
   ```

3. **Run the Program:**
   ```
   ./bin/VeriYapisi
   ```

4. **Clean Build Files (Optional):**
   ```
   make clean
   ```

## Features
- **DNA Management:** Simulates DNA data structure operations.
- **Gene and Chromosome Models:** Handles complex genetic models with linked DNA components.
- **Extensible Design:** Easily expandable due to modular code organization.

## Contributions
Contributions are welcome! Please fork the repository and submit a pull request.

## License
This project is licensed under the MIT License.
