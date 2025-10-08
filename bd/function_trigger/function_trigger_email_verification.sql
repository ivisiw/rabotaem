CREATE OR REPLACE FUNCTION fill_email_verification()
RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO email_verification (user_id,email) 
    VALUES (NEW.id, '');
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;