<?php

foreach ($categories as $category){
    echo "<h1>" . $category->getNom() . "</h1>";
    echo $category->getHtml();
}