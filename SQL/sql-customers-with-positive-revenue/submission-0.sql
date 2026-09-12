-- Write your query below
WITH positive_revenue AS (
    SELECT customer_id, SUM(revenue)
    FROM customers
    WHERE year = 2020
    AND revenue > 0
    GROUP BY customer_id
)

SELECT customer_id FROM positive_revenue