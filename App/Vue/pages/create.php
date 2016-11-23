<form method="post" action="index.php?persistance=XML&page=ajout">
    <table>
        <tr>
            <th><label for="titre">Titre</label></th>
            <td><input name="titre" type="text"></td>
        </tr>
        <tr>
            <th><label for="auteur">Auteur</label></th>
            <td><input name="auteur" type="text"></td>
        </tr>
        <tr>
            <th><label for="texte">Texte</label></th>
            <td><textarea name="texte"></textarea></td>
        </tr>
        <tr>
            <th><label for="categorie">Categorie</label></th>
            <td>
                <select name="categorie">
                <?php
                    foreach ($categories as $category){
                        echo "<option value='". $category->getNom() ."'>". $category->getNom() ."</option>";
                    }
                ?>
                </select>
            </td>
        </tr>
        <tr>
            <td colspan="2"><input type="submit" value="Ajouter"></td>
        </tr>
        <tr>
            <td colspan="2"><?php echo $message ?></td>
        </tr>
    </table>
</form>