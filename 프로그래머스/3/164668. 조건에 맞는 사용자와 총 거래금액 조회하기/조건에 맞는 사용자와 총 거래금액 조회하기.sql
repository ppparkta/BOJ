-- 코드를 입력하세요
SELECT g.user_id, g.nickname, sum(b.price) as total_sales
from USED_GOODS_BOARD b join USED_GOODS_USER g on b.WRITER_ID=g.user_id
where b.STATUS = 'DONE'
group by g.user_id, g.nickname
having sum(b.PRICE) >= 700000
order by total_sales;