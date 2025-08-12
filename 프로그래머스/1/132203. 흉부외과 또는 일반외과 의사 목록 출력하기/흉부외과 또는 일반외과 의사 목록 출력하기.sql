-- 코드를 입력하세요
SELECT d.dr_name, d.dr_id, d.mcdp_cd, substr(d.hire_ymd,1, 10)
from DOCTOR d
where d.mcdp_cd='CS' or d.mcdp_cd='GS'
order by d.HIRE_YMD desc, d.dr_name asc;