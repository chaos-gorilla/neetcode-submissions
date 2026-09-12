-- Write your query below
SELECT customer_id FROM (
    SELECT customer_id, SUM(revenue)
    FROM customers
    WHERE year = 2020
    AND revenue > 0
    GROUP BY customer_id
)