-- Write your query below
SELECT name FROM customers
WHERE id NOT IN (
    SELECT distinct customer_id FROM orders
)