-- Write your query below person and address
-- "person" Table
-- Column Name	Type
-- person_id	int
-- last_name	varchar
-- first_name	varchar

-- "address" Table 
-- Column Name	Type
-- address_id	int
-- person_id	int
-- city	varchar
-- state	varchar

SELECT p.first_name, p.last_name, a.city, a.state
FROM person p
LEFT JOIN address a ON p.person_id = a.person_id