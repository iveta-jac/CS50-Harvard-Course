-- List the names of all people who have directed a movie that received a rating of at least 9.0

SELECT name FROM people WHERE id IN
(SELECT person_id FROM directors WHERE movie_id IN
(SELECT movie_id FROM ratings WHERE rating >= 9.0));


/* Other solutions:

SELECT DISTINCT name FROM people 
JOIN directors ON people.id = directors.person_id 
JOIN ratings ON directors.movie_id = ratings.movie_id 
WHERE rating >= 9.0;

*/