package com.mycompany.app;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;
import java.util.Properties;

public class App
{
    public static void main( String[] args )
    {
        Logger logger = LoggerFactory.getLogger(App.class);
        Properties props = new Properties();

        try {
            props.load(ClassLoader.getSystemResourceAsStream("settings.properties"));
        } catch (IOException e) {
            logger.error("Failed to load settings.properties", e);
        }

        logger.info("The value of test.settings equals '{}'", props.get("test.setting"));
    }
}
