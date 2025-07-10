-- 코드를 입력하세요
-- 동일한 날짜, 회원, 상품 조합에서 하나의 판매 데이터만 존재한다. 
select user_id, product_id 
from online_sale
group by user_id, product_id
having count(*) >= 2
order by user_id, product_id desc;

