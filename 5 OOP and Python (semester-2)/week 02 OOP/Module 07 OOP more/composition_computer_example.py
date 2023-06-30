# interview = compositon vs inheritance difference

class CPU:
    def __init__(self, cores) -> None:
        self.cores = cores

class RAM:
    def __init__(self, size) -> None:
        self.size = size

class HardDrive:
    def __init__(self, capacity) -> None:
        self.capacity = capacity

# Computer has a CPU
# Computer has a RAM
# Computer has a HardDrive
class Computer:
    def __init__(self, cores, ram_size, hard_capacity) -> None:
        self.cpu = CPU(cores)
        self.ram_size = RAM(ram_size)
        self.hard_capacity = HardDrive(hard_capacity)

    def print_all(self):
        print(f'cpu: {self.cpu}cores, ram: {self.ram_size}GB, hard-disk: {self.hard_capacity}')

windows = Computer(8,32,512)


        