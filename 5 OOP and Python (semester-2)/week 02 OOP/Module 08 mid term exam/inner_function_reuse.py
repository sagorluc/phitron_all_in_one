class File:
    def __init__(self, filename):
        self.filename = filename

    def read(self):
        def open():
            # Open file
            return open(self.filename, 'r')

        file = open()  # call inner function to open file
        content = file.read()
        file.close()
        return content
    
nam = File('anything')
print(nam)
