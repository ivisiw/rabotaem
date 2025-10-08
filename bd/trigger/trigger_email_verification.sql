CREATE TRIGGER after_user_insert_email
    AFTER INSERT ON users
    FOR EACH ROW
    EXECUTE FUNCTION fill_email_verification();