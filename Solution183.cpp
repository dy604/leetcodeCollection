
//题目183，Customers Who Never Order 从未下单订购的顾客

//一个Customers表和一个Orders表，让我们找到从来没有下单的顾客
//1、
SELECT Name AS Customers FROM Customers
WHERE Id NOT IN (SELECT CustomerId FROM Orders);

//2、
SELECT Name AS Customers FROM Customers
LEFT JOIN Orders ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;

//3、
SELECT Name AS Customers FROM Customers c
WHERE NOT EXISTS (SELECT * FROM Orders o WHERE o.CustomerId = c.Id);
