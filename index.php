<?php

    define("RACINE", __DIR__);

    // Autoloader
    use App\Controller\BaseController;
    use App\Autoloader;

    require (RACINE."/App/__autoload.inc");
    Autoloader::register();

    // Controleur
    ob_start();

    // Definir la le controlleur a appeller
    $p = $_GET['page'];
    if($p == "accueil"){
        $controleur = new BaseController();
        $controleur->index();
    }
    elseif($p == "ajout"){
        $controleur = new BaseController();
        $controleur->addArticle();
    }
    else{
        echo "Not FOund";
    }

    $content = ob_get_clean();

    require ("App/Vue/layout.php");
?>