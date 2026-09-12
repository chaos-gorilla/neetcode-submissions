-- Write your query below
WITH ids_who_made_a_sale AS (
    SELECT seller_id
    FROM orders
    WHERE EXTRACT(YEAR FROM sale_date) = 2020
)

SELECT seller_name
FROM seller
WHERE seller_id NOT IN (
    SELECT seller_id FROM ids_who_made_a_sale
)
ORDER BY seller_name