# Write your MySQL query statement below
select p.firstname,p.lastName, A.city, A.state 
from Person p 
left outer join
Address A 
on p.personId=A.personId