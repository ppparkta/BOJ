SELECT MCDP_CD as 진료과코드,count(*) 월예약건수
FROM APPOINTMENT
where '2022-05'=TO_CHAR(APNT_YMD,'YYYY-MM')
group by MCDP_CD
order by 월예약건수, MCDP_CD