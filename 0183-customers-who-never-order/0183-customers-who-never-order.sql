# Write your MySQL query statement below
select c.name as Customers 
from customers c 
left outer join orders o 
on c.id=o.customerId 
where o.id is null