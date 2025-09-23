-- 코드를 입력하세요
SELECT b.category, sum(bs.SALES)
from book b
inner join BOOK_SALES bs on b.book_id = bs.book_id
where substr(bs.SALES_DATE, 1, 7) = '2022-01'
group by b.category
order by b.category;