<?php
// AWS SDKライブラリのローディング
include_once dirname(__FILE__)."/../vendor/autoload.php";

use Aws\S3\S3Client;

    $s3client = S3Client::factory([
/*
        'credentials' => [
            'key' => env('AWS_ACCESS_KEY_ID'),
            'secret' => env('AWS_SECRET_ACCESS_KEY'),
        ],
*/
        'region' => 'ap-northeast-1',
        'version' => 'latest',
    ]);
