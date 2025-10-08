CREATE OR REPLACE FUNCTION fill_ads_photo()
RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO ads_photo (ads_id) 
    VALUES (NEW.id, '');
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;