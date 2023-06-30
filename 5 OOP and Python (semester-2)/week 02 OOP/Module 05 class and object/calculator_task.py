class calculator:
    name = 'casio calculator' # atribute of class

    def add(num1, num2): # method of class
        sum = num1 + num2
        return sum
    
    def deduct( num1, num2): # method of class
        sub = num1 - num2
        return sub
    
    def double( num1, num2): # method of class
        mul = num1 * num2
        return mul
    
    def vag(num1, num2): # method of class
        div = num1 / num2
        return div

a = 56
b = 25 
cal_name = calculator().name
print('brand name of calculator',cal_name)  

add = calculator.add(a,b)
print('total addition: ',add)

deduct = calculator.deduct(a,b)
print('total substruction: ',deduct)

double = calculator.double(a,b)
print('total multiple: ',double)

vag = calculator.vag(a,b)
print('total divided: ',vag)