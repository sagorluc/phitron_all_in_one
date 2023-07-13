/* Customers (id, Name), Orders (id, customerId) 
    We have these two tables. Give me the names of
    the customers who never ordered.
*/

SELECT Customers.Name AS Customers
FROM Customers
LEFT JOIN Orders
ON Customers.id = Orders.customerId
WHERE Orders.customerId IS NULL;
