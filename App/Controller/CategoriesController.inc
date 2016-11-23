<?php

namespace App\Controller;

/**
 * Created by PhpStorm.
 * User: leetspeakv2
 * Date: 21/11/16
 * Time: 12:22
 */
class CategoriesController extends Controller
{
    public function index(){
        self::checkPersistance();
        $categories = self::$persistanceProvider->getCategories();
        $this->render("index", compact('categories'));
    }
}