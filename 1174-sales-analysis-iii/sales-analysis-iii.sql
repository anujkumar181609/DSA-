# Write your MySQL query statement below
SELECT Product.product_id, Product.product_name FROM Product
JOIN Sales
ON Product.product_id = Sales.product_id
GROUP BY Product.product_id
HAVING MAX(sale_date) <= '2019-03-31' AND MIN(sale_date)>='2019-01-01'