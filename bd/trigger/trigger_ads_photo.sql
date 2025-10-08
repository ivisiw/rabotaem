CREATE TRIGGER after_ads_photo
    AFTER INSERT ON ads
    FOR EACH ROW
    EXECUTE FUNCTION fill_email_verification();