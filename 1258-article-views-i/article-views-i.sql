# Write your MySQL query statement below
SELECT DISTINCT author_id AS id FROM Views
WHERE EXISTS (
    SELECT 1 FROM Views x
    WHERE x.author_id= Views.author_id AND x.author_id= Views.viewer_id
)
ORDER BY id 