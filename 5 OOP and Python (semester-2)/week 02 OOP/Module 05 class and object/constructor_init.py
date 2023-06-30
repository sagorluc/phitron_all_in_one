class pen:
    made_by = 'bangladesh'

    # constructor of python
    def __init__ (self,pen_woner, pen_made, pen_price, pen_color):
        self.woner = pen_woner # inside the constructor all are instance attribute
        self.made = pen_made
        self.price = pen_price
        self.color = pen_color


my_pen = pen("sagor", 'bangladesh',  32, 'white')
#print(my_pen.woner, my_pen.made, my_pen.price, my_pen.color)
f_pri = f"woner: {my_pen.woner}, made by: {my_pen.made}, total price: {my_pen.price}, pen color: {my_pen.color} "
print(f_pri)

j_pen = pen('jakir', 'japan', 10, 'blue')
f_pen = j_pen.woner, j_pen.made, j_pen.price, j_pen.color
print(f_pen)

s_pen = pen('saiful', 'korea', 5, 'green')
print(s_pen.woner, s_pen.made, s_pen.color, s_pen.price)

i_pen = pen('ismal', 'china', 2, 'orange')
print(i_pen.woner, i_pen.made, i_pen.price, i_pen.color)