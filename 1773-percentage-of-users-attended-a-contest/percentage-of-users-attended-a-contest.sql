# Write your MySQL query statement below
SELECT Register.contest_id, ROUND(COUNT(Register.user_id)*100/ (SELECT COUNT(Users.user_id) FROM Users),2) AS percentage FROM Register
JOIN Users
ON Users.user_id= Register.user_id
GROUP BY Register.contest_id
ORDER BY  percentage DESC, Register.contest_id ASC;