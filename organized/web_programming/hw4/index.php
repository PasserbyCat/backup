<?php
// Include database configuration file
require_once 'dbConfig.php';

// Include URL Shortener library file
require_once 'Shortener.class.php';

// Initialize Shortener class and pass PDO object
$shortener = new Shortener($db);

// Long URL
$longURL = $_GET["input"];

// Prefix of the short URL 
$shortURL_Prefix = 'http://localhost/1081447/'; // without URL rewrite

try{
    // Get short code of the URL
    $shortCode = $shortener->urlToShortCode($longURL);
    
    // Create short URL
    $shortURL = $shortURL_Prefix.$shortCode;
    
    // Display short URL
    echo "<p>Short URL: <a href = '".$shortURL."'>".$shortURL."</a></p>";
}catch(Exception $e){
    // Display error
    echo $e->getMessage();
}