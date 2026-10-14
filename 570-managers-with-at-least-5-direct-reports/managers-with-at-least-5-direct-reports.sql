# Write your MySQL query statement below
SELECT name FROM Employee
WHERE id IN (
    SELECT e1.managerId FROM Employee e1
    GROUP BY e1.managerId
    HAVING COUNT(*)>=5
)