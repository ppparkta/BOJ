-- 코드를 입력하세요 
SELECT i.INGREDIENT_TYPE, sum(f.TOTAL_ORDER) as TOTAL_ORDER
from first_half f join icecream_info i on f.flavor = i.flavor
group by i.ingredient_type
order by f.total_order asc;