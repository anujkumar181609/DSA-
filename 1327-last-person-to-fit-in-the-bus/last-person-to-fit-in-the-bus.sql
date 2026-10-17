# Write your MySQL query statement below
SELECT person_name FROM(
    SELECT person_name, SUM(weight) OVER(ORDER BY turn) AS result FROM Queue
)
AS RED WHERE result<=1000
ORDER BY result DESC
LIMIT 1