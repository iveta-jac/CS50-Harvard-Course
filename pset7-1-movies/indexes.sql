CREATE INDEX directors_movie_id_index ON directors (movie_id);
CREATE INDEX directors_person_id_index ON directors (person_id);
CREATE INDEX movies_id_index ON movies (id);
CREATE INDEX movies_title_index ON movies (title);
CREATE INDEX movies_year_index ON movies (year);
CREATE INDEX people_birth_index ON people (birth);
CREATE INDEX people_id_index ON people (id);
CREATE INDEX people_name_index ON people (name);
CREATE INDEX ratings_movie_id_index ON ratings (movie_id);
CREATE INDEX ratings_rating_index ON ratings (rating);
CREATE INDEX ratings_votes_index ON ratings (votes);
CREATE INDEX stars_movie_id_index ON stars (movie_id);
CREATE INDEX stars_person_id_index ON stars (person_id);