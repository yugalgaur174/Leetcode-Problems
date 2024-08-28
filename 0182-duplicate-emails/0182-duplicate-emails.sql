# Write your MySQL query statement below
-- select e1.email as Email from Person e1 join Person e2 on e1.id !=e2.id where e1.email=e2.email;
select email as Email from Person group by email having count(email)>1;