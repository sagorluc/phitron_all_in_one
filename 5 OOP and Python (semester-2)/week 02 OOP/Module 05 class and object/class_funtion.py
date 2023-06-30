def call_to():
    print('some one who are not busy right now')
    return 'yes call done'

class laptop:
    price = 25674
    color = 'black'
    fetures = ['camera', 'spaker','web-camera']

    def call_to(self):
        print('i dont know who')
    
    def sand_sms(self,num, sms):
        t = f"call to this {num} number, and sms {sms} this number"
        return t
    
my_laptop = laptop()
# print(my_laptop.fetures)
# my_laptop.call_someone()
call_to()

# a = 2357 
# b = 86545
# ans = my_laptop.sand_sms(a,b)
# print(ans)


