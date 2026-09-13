# Write your MySQL query statement below

-- date_format(trans_date,'%Y-%m')   is mai aagar %Y likhoge toh YYYY(2018) aase karke pura year aata h %y mai YY(18) aata h
-- is pure example mai group by karne ke baat aggregate kaise acche se use kar h vohh sikhay ah  

select date_format(trans_date,'%Y-%m') as month,country,count(id) as trans_count,sum(state='approved') as approved_count,sum(amount) as trans_total_amount,sum(if(state='approved' , amount, 0)) as approved_total_amount from Transactions group by date_format(trans_date,'%Y-%m'),country;