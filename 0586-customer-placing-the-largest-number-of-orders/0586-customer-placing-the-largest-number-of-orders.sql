# Write your MySQL query statement below
-- select customer_number from orders
-- group by customer_number
-- having count(order_number)>=all(
--     select count(order_number) from orders 
--     group by customer_number)


    SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(order_number) DESC
LIMIT 1;