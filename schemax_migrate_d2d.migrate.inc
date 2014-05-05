<?php

/**
 * Implements hook_migrate_api().
 */
function schemax_migrate_d2d_migrate_api() {
  $api = array(
    'api' => 2,
    // Give the group a human-readable title
    'groups' => array(
      'D6content' => array(
        'title' => t('D6 Content'),
      ),
    ),
  );
  return $api;
}
