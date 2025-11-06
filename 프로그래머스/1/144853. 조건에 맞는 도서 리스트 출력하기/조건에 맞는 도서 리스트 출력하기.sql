-- 코드를 입력하세요
SELECT b.book_id as BOOK_ID, substr( b.PUBLISHED_DATE, 1, 10) as PUBLISHED_DATE
from book b
where year(b.PUBLISHED_DATE) = '2021' and CATEGORY = '인문'
order by b.PUBLISHED_DATE asc;