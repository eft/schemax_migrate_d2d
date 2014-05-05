<?php

/**
 * Common mappings for Drupal 6 node migrations.
 */
abstract class SchemaxNodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_legacy_nid', 'nid')
         ->description('We have a common field to save the D6 nid');
  }
}

class NewsMigration extends SchemaxNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    //$this->sourceFields['lead_graphic'] = 'Lead graphic string from D6';
    //$this->sourceFields['summary'] = 'Summary string from D6';

    parent::__construct($arguments);

    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')
         ->defaultValue('schemax_filtered_html');

    // Disable comments
    $this->addFieldMapping('comment')
        ->defaultValue(FALSE);

    // Make sure not promoted to front page
    $this->addFieldMapping('promote')
        ->defaultValue(FALSE);

  }
}
