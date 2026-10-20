# Write your MySQL query statement below
SELECT product_id, year AS first_year, quantity, price FROM Sales
WHERE (product_id, year) IN(
    SELECT x.product_id, MIN(x.year) FROM Sales x
    
    GROUP BY x.product_id
)
