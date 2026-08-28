# Write your MySQL query statement below
# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary
from Employee e inner join Department d on d.id=e.departmentId
where 3>(select count(distinct e2.salary) from employee e2
where e2.departmentId=e.departmentId
AND e2.salary>e.salary)