# Must be run as a redirected file when launching mysql
# mysql -u myid -p mydb < transaction.sql

start transaction;
insert into branch values ( 'TinselTown', 'Los Angeles', 5000000 );
insert into branch values ( 'Redwood', 'San Francisco', 6000500 );
commit;
