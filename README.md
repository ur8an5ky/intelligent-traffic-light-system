# Intelligent Traffic Light System
## General information
This is a project created as part of the recruitment process. This is a simulation of intelligent traffic lights at an intersection. The goal of the task is to design and implement a system that adjusts the cycles of traffic lights based on the traffic volume on each road.  
The basic functionality of the program is to accept a list of commands in the form of a JSON file. Each command defines an action to be performed by the system at an intersection. E.g.:  
```json
{
    "commands": [
    {
      "type": "addVehicle",
      "vehicleId": "vehicle1",
      "startRoad": "south",
      "endRoad": "north"
    },
    {
      "type": "addVehicle",
      "vehicleId": "vehicle2",
      "startRoad": "north",
      "endRoad": "south"
    },
    {
      "type": "step"
    },
    {
      "type": "step"
    },
    {
      "type": "addVehicle",
      "vehicleId": "vehicle3",
      "startRoad": "west",
      "endRoad": "south"
    },
    {
      "type": "addVehicle",
      "vehicleId": "vehicle4",
      "startRoad": "west",
      "endRoad": "south"
    },
    {
      "type": "step"
    },
    {
      "type": "step"
    }
  ]
}
```
* Command `addVehicle`: adds a vehicle on the indicated start road (`startRoad`) with the goal of reaching the end road (`endRoad`).
* Command `step`: performs a simulation step during which the first vehicles on the road that currently has a green light pass through the intersection.

The expected output from the simulation is a JSON containing a list of vehicles that left the intersection after each simulation step. E.g.:  
```json
{
  "stepStatuses": [
    {
      "leftVehicles": [
        "vehicle2",
        "vehicle1"
      ]
    },
    {
      "leftVehicles": []
    },
    {
      "leftVehicles": [
        "vehicle3"
      ]
    },
    {
      "leftVehicles": [
        "vehicle4"
      ]
    }
  ]
}
```
* `stepStatuses`: contains a list of statuses for each step of the simulation.
* `leftVehicles`: contains a list of identifiers of vehicles that left the intersection in a given step.

## Download and launch instructions
Use WSL or Linux.
1. In the terminal, type: `git clone https://github.com/ur8an5ky/intelligent-traffic-light-system.git`
2. After succesful clone, type `cd intelligent-traffic-light-system`
3. Make sure you have the Clang compiler installed (`clang --version`) - if not, install it (`sudo apt update` and then `sudo apt install clang`)
4. Install Jansson library, type: `sudo apt update` and then `sudo apt install libjansson-dev`. Jansson is a lightweight library for handling JSON (JavaScript Object Notation) format in C. If you have this library installed, skip this step.
5. Execute `make` command.
6. Execute `./main data.json output.json` (`data.json` is a sample input file located in **data/** directory, `output.json` is a sample output file name located in **output/** directory).
7. If you want, you can check if the application has any memory or optimization errors using the Valgrind tool:
`valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind_output.txt ./main data.json output.json`
Output with error information will be in the file `valgrind_output.txt`.