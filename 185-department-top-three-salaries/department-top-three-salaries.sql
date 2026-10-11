# Write your MySQL query statement below
SELECT Department, Employee, Salary FROM(
    SELECT Department.name AS Department, Employee.name AS Employee , Employee.salary AS Salary, DENSE_RANK() OVER(PARTITION BY Employee.departmentId ORDER BY Employee.salary DESC) AS result FROM Employee
    JOIN Department
    ON Employee.departmentId= Department.id
) AS RED WHERE result <=3;