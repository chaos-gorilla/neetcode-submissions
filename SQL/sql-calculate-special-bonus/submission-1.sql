-- Write your query below
SELECT employee_id,
    CASE
        WHEN MOD(employee_id, 2) = 1 AND NOT starts_with(name, 'M') THEN salary
        ELSE 0
    END as bonus
FROM employees 
ORDER BY employee_id