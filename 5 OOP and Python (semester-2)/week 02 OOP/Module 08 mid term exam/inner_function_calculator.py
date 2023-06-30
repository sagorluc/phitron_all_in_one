class Sum:
    def __init__(self, a, b) -> None:
        self.a = a
        self.b = b

    def add(self):
        def valid_input():
            if not isinstance(self.a, (int,float)) or not isinstance(self.b, (int, float)):
                raise ValueError('Invalid input')
            
        valid_input()
        return self.a + self.b
    
ans = Sum(5,6)
print(ans.add())