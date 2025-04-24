import json
import sys

def parse_commands(json_file):
    with open(json_file, 'r') as file:
        data = json.load(file)

    vehicles = []
    for command in data['commands']:
        if command['type'] == 'addVehicle':
            vehicle_info = [
                command['vehicleId'],
                command['startRoad'],
                command['endRoad']
            ]
            vehicles.append(vehicle_info)
            print(f"{','.join(map(str, vehicle_info))}")
        elif command['type'] == 'step':
            print("Step")

    return vehicles

if __name__ == "__main__":
    json_file = sys.argv[1]
    vehicles = parse_commands(json_file)
    
    print(json.dumps([list(v) for v in vehicles]))