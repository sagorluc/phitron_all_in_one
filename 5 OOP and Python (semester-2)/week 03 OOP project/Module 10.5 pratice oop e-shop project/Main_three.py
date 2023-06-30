from User_one import User, Customer
from Seller_all_method_two import Seller, Product

def main():

    c = Customer(1, 'sagor@gmail.com', 125)
    c.Create_account('sagor@gmail.com', 125)
    c.log_in('sagor@gmail.com', 125)

    seller_1 = Seller(2, 'jakir@gmail.com', 564)
    seller_1.Create_account('jakir@gmail.com',564)
    seller_1.log_in('jakir@gmail.com', 564)

    # publish product to sell
    product_1 = Product('Shoes',1200, 10)
    product_2 = Product('T-shirt', 5600, 0)
    product_3 = Product('Money bag', 2300, 1)

    seller_1.Add_product(product_1)
    seller_1.Add_product(product_2)
    seller_1.Add_product(product_3)

    seller_1.Veiw_product()



if __name__ == '__main__':
    main()